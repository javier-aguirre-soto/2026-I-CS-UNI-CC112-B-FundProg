#ifndef __TYPES_H__
#define __TYPES_H__

// Aritmetica
using T1  = int;
using T2  = double;

using TT1 = long long;

// Utilidad
using SUT1  = int;
using SUTT1 = long long;

using UUT1 = unsigned int;
using UUTT1 = unsigned long long;

//#define __U__
#if defined __U__
    using UT1  = UUT1; 
    using UTT1 = UUTT1;
#else
    using UT1  = SUT1;
    using UTT1 = SUTT1;
#endif
typedef bool (*CompFunc)(T1, T1);
#endif // __TYPES_H__