/*++

Copyright (c) 2005 Microsoft Corporation

All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

File Name:

   bstrops.h

Abstract:

   The ATL3 implementation of CComBSTR does not include const WCHAR* comparison
   operators or a suitable equivalent. As a result comparison operations with
   CComBSTR cause the compiler to cast the CComBSTR instance to a const BSTR. This
   operator is defined and returns a pointer to the underlying BSTR. The comparison
   is then made between the address of the underlying BSTR and the compare string
   which is not what is intended. This file provides a set of operators that handle
   this eventuality by defining comparison operators between CComBSTR and LPCWSTR that
   cast away the LPCWSTR constness and make the comparison with the operators that
   are supported by CComBSTR.

--*/

#pragma once

/*++

Routine Name:

    operator==

Routine Description:

    Equality operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    true  - the strings compare
    false - otherwise

--*/
inline bool
operator==(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return bstr.operator==(const_cast<PWSTR>(psz));
}

/*++

Routine Name:

    operator!=

Routine Description:

    Inequality operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    truw  - the strings do not compare
    false - otherwise

--*/
inline bool
operator!=(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return !(bstr.operator==(const_cast<PWSTR>(psz)));
}

/*++

Routine Name:

    operator<

Routine Description:

    Less than operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    true  - the CComBSTR string is less than the compare string
    false - otherwise

--*/
inline bool
operator<(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return bstr.operator<(const_cast<PWSTR>(psz));
}

/*++

Routine Name:

    operator>

Routine Description:

    Greater than operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    true  - the CComBSTR string is greater than the compare string
    false - otherwise

--*/
inline bool
operator>(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return !bstr.operator<(const_cast<PWSTR>(psz)) && !bstr.operator==(const_cast<PWSTR>(psz));
}

/*++

Routine Name:

    operator>=

Routine Description:

    Greater than or equal operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    true  - the CComBSTR string is greater than or equal to the compare string
    false - otherwise

--*/
inline bool
operator>=(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return !bstr.operator<(const_cast<PWSTR>(psz));
}

/*++

Routine Name:

    operator<=

Routine Description:

    Less than or equal operator

Arguments:

    bstr - const reference to a CComBSTR
    psz  - pointer to the WCHAR string to compare

Return Value:

    true  - the CComBSTR string is less than or equal to the compare string
    false - otherwise

--*/
inline bool
operator<=(
    __in CONST CComBSTR& bstr,
    __in LPCWSTR         psz
    )
{
    return bstr.operator<(const_cast<PWSTR>(psz)) || bstr.operator==(const_cast<PWSTR>(psz));
}


