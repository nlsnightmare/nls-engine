#pragma once
#include <cmath>

namespace math{

    template<typename T>
    int sign(T val){
	return (T(0) < val) - (val < T(0));
    }

    template<typename T>
    T minabs(T v1, T v2){
	if (std::abs(v1) < std::abs(v2))
	    return v1;
	else
	    return v2;
    }
    
}
