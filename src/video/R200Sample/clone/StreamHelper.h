//-----------------------------------------------------------------------
//
// <copyright file="StreamHelper.h" company="Microsoft">
//    Copyright © 2004-2006 Microsoft Corporation.  All rights reserved.
// </copyright>
//
// Module:
//        StreamHelper.h
//
// Description:
//        Declaration of the classes used to unpack the view data
//
//-----------------------------------------------------------------------
#pragma once

static DISPLAY_DEVICE s_dd;

const int c_iDeviceKeyCch = sizeof(s_dd.DeviceKey)/sizeof(s_dd.DeviceKey[0]);
const int c_iDeviceNameCch = sizeof(s_dd.DeviceName)/sizeof(s_dd.DeviceName[0]);
const int c_iDeviceStringCch = sizeof(s_dd.DeviceString)/sizeof(s_dd.DeviceString[0]);

class CSourceTargets
{
private:
    ULONG       _ulSource;
    ULONG       _ulCount;
    ULONG *     _pTargets;

    void CleanUp()
    {
        if (NULL != _pTargets)
        {
            delete [] _pTargets;
            _pTargets = NULL;
            _ulCount = 0;
        }
    }

public:
    CSourceTargets()
        : _ulSource(0),
          _ulCount(0),
          _pTargets(NULL)
    {
    }
    virtual ~CSourceTargets()
    {
        CleanUp();
    }

    void SetSource(ULONG ulSource) { _ulSource = ulSource; }

    ULONG GetSource() const { return _ulSource; }

    BOOL AllocateTargets(ULONG ulCount)
    {
        CleanUp();

        if (0 != ulCount)
        {
            _pTargets = new ULONG[ulCount];

            if (NULL != _pTargets)
            {
                _ulCount = ulCount;
            }
        }

        return (NULL != _pTargets) ? TRUE : FALSE;
    }

    ULONG GetCount() const { return _ulCount; }

    BOOL Assign(ULONG ulIndex, ULONG ulTarget)
    {
        BOOL fReturn = FALSE;

        if (NULL != _pTargets)
        {
            if (ulIndex < _ulCount)
            {
                _pTargets[ulIndex] = ulTarget;
                
                fReturn = TRUE;
            }
        }

        return fReturn;
    }

    ULONG GetTarget(ULONG ulIndex) const
    {
        ULONG ulTarget = 0xffffffff;

        if (NULL != _pTargets)
        {
            if (ulIndex < _ulCount)
            {
                ulTarget = _pTargets[ulIndex];
            }
        }
        
        return ulTarget;
    }

    ULONG * GetTargetBuffer()
    {
        return _pTargets;
    }

    void Clear()
    {
        CleanUp();
    }
};

class CAdapter
{
private:
    WCHAR                       _adapterName[c_iDeviceKeyCch];
    CSourceTargets *            _pSourceTargets;
    ULONG                       _ulCount;

public:
    CAdapter()
    {
        _adapterName[0] = L'\0';
        _pSourceTargets = NULL;
        _ulCount = 0;
    }
    virtual ~CAdapter() 
    {
        if (_pSourceTargets)
        {
            delete [] _pSourceTargets;
            _pSourceTargets = NULL;
            _ulCount = 0;
        }
    }

    LPCWSTR GetAdapterName() const { return _adapterName; }

    void SetAdapterName(LPCWSTR adapterName)
    {
        (void)::StringCchCopyW(_adapterName, c_iDeviceKeyCch, adapterName);
    }
    
    // Need assignment operator when resizing vector containing
    // this object.
    //
    CAdapter& operator=(const CAdapter& rhs)
    {
        if (this != &rhs)
        {
            SetAdapterName(rhs._adapterName);

            HRESULT hr = S_OK;

            // get size of rhs vector
            SIZE_T sizeRHS = rhs.GetNumSources();

            // check size of this vector
            SIZE_T sizeThis = GetNumSources();

            if (sizeRHS != sizeThis)
            {
                // resize vector
                delete [] _pSourceTargets;

                _pSourceTargets = new CSourceTargets[sizeRHS];

                if (NULL == _pSourceTargets)
                {
                    _ulCount = 0;

                    hr = E_OUTOFMEMORY;
                }
                else
                {
                    _ulCount = (ULONG)sizeRHS;
                }
            }

            if (SUCCEEDED(hr))
            {
                // now copy each element
                int i = 0;

                for ( i = 0 ; i < int(sizeRHS) ; i++ )
                {
                    _pSourceTargets[i] = rhs._pSourceTargets[i];
                }
            }
        }

        return *this;
    }

    ULONG GetNumSources() const
    {
        return _ulCount;
    }

    HRESULT SetSourceTargetsVectorSize(ULONG ulNumSources)
    {
        HRESULT hr = E_OUTOFMEMORY;

        // allocate memory for available source identifiers
        if (NULL != _pSourceTargets)
        {
            delete [] _pSourceTargets;
            _ulCount = 0;
        }

        _pSourceTargets = new CSourceTargets[ulNumSources];

        if (NULL != _pSourceTargets)
        {
            _ulCount = ulNumSources;

            hr = S_OK;
        }

        return hr;
    }

    HRESULT SetSource(ULONG ulSourceIndex, ULONG ulSourceId)
    {
        HRESULT hr = E_FAIL;

        if (ulSourceIndex < GetNumSources())
        {
            hr = S_OK;

            _pSourceTargets[ulSourceIndex].SetSource(ulSourceId);
        }

        return hr;
    }

    HRESULT AllocateTargetsOnSource(ULONG ulSourceIndex, ULONG ulNumTargets)
    {
        HRESULT hr = E_FAIL;

        if (ulSourceIndex < GetNumSources())
        {
            if (_pSourceTargets[ulSourceIndex].AllocateTargets(ulNumTargets))
            {
                hr = S_OK;
            }
        }

        return hr;
    }

    HRESULT SetTargetOnSource(ULONG ulSourceIndex, ULONG ulTargetIndex, ULONG ulTargetId)
    {
        HRESULT hr = E_FAIL;

        if (ulSourceIndex < GetNumSources())
        {
            if (_pSourceTargets[ulSourceIndex].Assign(ulTargetIndex, ulTargetId))
            {
                hr = S_OK;
            }
        }

        return hr;
    }

};

class CAdapterCollection
{
private:
    CAdapter *              _pAdapter;
    ULONG                   _ulCount;

public:
    CAdapterCollection() : _pAdapter(NULL), _ulCount(0) {}
    virtual ~CAdapterCollection() 
    {
        if (_pAdapter)
        {
            delete [] _pAdapter;
            _pAdapter = NULL;
            _ulCount = 0;
        }
    }

    CAdapter * GetAdapter(LPCWSTR adapterName)
    {
        SIZE_T count = GetAdapterCount();
        ULONG ulLoop = 0;
        BOOL fFound = FALSE;
        ULONG ulIndex = 0;

        for ( ulLoop = 0 ; ulLoop < count ; ulLoop++ )
        {
            if (CSTR_EQUAL == CompareStringW(LOCALE_USER_DEFAULT, 0, adapterName, -1, _pAdapter[ulLoop].GetAdapterName(), -1))
            {
                fFound = TRUE;
                ulIndex = ulLoop;
                break;
            }
        }

        return fFound ? &_pAdapter[ulIndex] : NULL;
    }

    BOOL AddAdapter(LPCWSTR adapterName)
    {
        BOOL fReturn = FALSE;

        if (NULL == GetAdapter(adapterName))
        {
            SIZE_T size = GetAdapterCount();

            ++size;

            CAdapter * pAdapter = new CAdapter[size];

            if (NULL != pAdapter)
            {
                _ulCount = (ULONG)size;

                // copy over existing items
                int i = 0;

                for ( i = 0 ; i < int(size - 1) ; i++ )
                {
                    pAdapter[i] = _pAdapter[i];
                }

                // work with latest entry
                pAdapter[size - 1].SetAdapterName(adapterName);

                // Now use the new array
                if (NULL != _pAdapter)
                {
                    // free up the old array
                    delete [] _pAdapter;
                }

                _pAdapter = pAdapter;

                fReturn = TRUE;
            }
        }

        return fReturn;
    }

    SIZE_T GetAdapterCount() const
    {
        return _ulCount;
    }
};

class CStreamHelper
{
private:
    CAdapterCollection      _adapterCollection;

    HRESULT AddAdapter(const Adapter& adapter, 
                       IStream * pIStream);

    HRESULT ExtractTopologyDataFromStream(IStream * pIStream);

public:
    CStreamHelper() {}
    ~CStreamHelper() {}

    HRESULT Unpack(IStream * pIStream);
};

