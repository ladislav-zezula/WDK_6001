//-----------------------------------------------------------------------
//
// <copyright file="StreamHelper.cpp" company="Microsoft">
//    Copyright © 2004-2006 Microsoft Corporation.  All rights reserved.
// </copyright>
//
// Module:
//        StreamHelper.cpp
//
// Description:
//        Implements classes and functions used to unpack view data
//
//-----------------------------------------------------------------------
#include <windows.h>
#include <strsafe.h>
#include "CloneHelper.h"
#include "StreamHelper.h"

template<class T> HRESULT Read(T& t, IStream * pIStream)
{
    HRESULT hr = S_OK;

    ULONG cbRead = 0;

    hr = pIStream->Read((void*)&t, sizeof(T), &cbRead);
    
    if (SUCCEEDED(hr))
    {
        if (cbRead != sizeof(T))
        {
            hr = E_FAIL;
        }
    }

    return hr;
}

static HRESULT ExtractDisplayDataFromStream(IStream * pIStream)
{
    // now read DisplayModes
    DisplayModes displayModes;

    HRESULT hr = Read<DisplayModes>(displayModes, pIStream);

    if (SUCCEEDED(hr))
    {
        hr = E_UNEXPECTED;

        // extract the number of displays
        int iNumDisplays = displayModes.numDisplayModes;

        if (iNumDisplays)
        {
            DisplayMode displayMode = displayModes.displayMode[0];

            int i = 1;

            for ( i = 1 ; i < iNumDisplays ; i++ )
            {
                hr = Read<DisplayMode>(displayMode, pIStream);
            }
        }
    }

    return hr;
}

static HRESULT SetSourcesOnAdapter(CAdapter * pAdapter, 
                                   ULONG ulSourceIndex, 
                                   const Sources& sources, 
                                   IStream * pIStream)
{
    // set Sources data into adapter
    HRESULT hr = pAdapter->SetSource(ulSourceIndex, sources.sourceId);

    if (SUCCEEDED(hr))
    {
        // set target info
        int iNumTargets = sources.numTargets;

        if (iNumTargets)
        {
            hr = pAdapter->AllocateTargetsOnSource(ulSourceIndex, (ULONG)iNumTargets);

            if (SUCCEEDED(hr))
            {
                // write out the targets
                hr = pAdapter->SetTargetOnSource(ulSourceIndex, 0, sources.aTargets[0]);

                if (SUCCEEDED(hr))
                {
                    // read in the rest of the targets
                    ULONG ulTarget = 1;

                    ULONG target;

                    for ( ulTarget = 1 ; ulTarget < (ULONG)iNumTargets ; ulTarget++ )
                    {
                        hr = Read<ULONG>(target, pIStream);

                        if (SUCCEEDED(hr))
                        {
                            hr = pAdapter->SetTargetOnSource(ulSourceIndex, ulTarget, target);
                        }

                        if (FAILED(hr))
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    return hr;
}

HRESULT CStreamHelper::AddAdapter(const Adapter& adapter, 
                                  IStream * pIStream)
{
    HRESULT hr = E_FAIL;

    // Adapter adapter;
    if (_adapterCollection.AddAdapter(adapter.AdapterName))
    {
        CAdapter * pAdapter = _adapterCollection.GetAdapter(adapter.AdapterName);

        if (pAdapter)
        {
            // set number of sources
            int iNumSources = adapter.numSources;

            if (iNumSources)
            {
                hr = pAdapter->SetSourceTargetsVectorSize((ULONG)iNumSources);

                if (SUCCEEDED(hr))
                {
                    // set Sources data into adapter
                    hr = SetSourcesOnAdapter(pAdapter, 0, adapter.sources[0], pIStream);

                    if (SUCCEEDED(hr))
                    {
                        // read in next Sources

                        ULONG ulSources = 1;

                        Sources sources;

                        for ( ulSources = 1 ; ulSources < (ULONG)iNumSources ; ulSources++ )
                        {
                            // read in sources
                            hr = Read<Sources>(sources, pIStream);

                            if (SUCCEEDED(hr))
                            {
                                hr = SetSourcesOnAdapter(pAdapter, ulSources, sources, pIStream);
                            }

                            if (FAILED(hr))
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return hr;
}

HRESULT CStreamHelper::ExtractTopologyDataFromStream(IStream * pIStream)
{
    // Extract toplogy data from IStream

    Adapters adapters;

    HRESULT hr = Read<Adapters>(adapters, pIStream);

    if (SUCCEEDED(hr))
    {
        // get number of adapters
        int iNumAdapters = adapters.numAdapters;
        
        hr = AddAdapter(adapters.adapter[0], pIStream);

        if (SUCCEEDED(hr))
        {
            // read next adapter
            Adapter adapter;

            int i = 1;

            for ( i = 1 ; i < iNumAdapters ; i++ )
            {
                hr = Read<Adapter>(adapter, pIStream);

                if (SUCCEEDED(hr))
                {
                    hr = AddAdapter(adapter, pIStream);
                }

                if (FAILED(hr))
                {
                    break;
                }
            }
        }
    }

    return hr;
}

HRESULT CStreamHelper::Unpack(IStream * pIStream)
{
    ULONG ulSize = 0;

    HRESULT hr;

    // Now extract data from IStream
    hr = Read<ULONG>(ulSize, pIStream);

    if (SUCCEEDED(hr))
    {
        // Extract display data from IStream
        hr = ExtractDisplayDataFromStream(pIStream);

        if (SUCCEEDED(hr))
        {
            // Extract toplogy data from IStream
            hr = ExtractTopologyDataFromStream(pIStream);
        }
    }

    return hr;
}

