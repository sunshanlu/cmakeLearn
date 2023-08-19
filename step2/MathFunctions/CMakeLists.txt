option(USE_MY "use my define out standard library" OFF)

add_library(MathFunctions MathFunctions.cxx mySqrt.cxx)

if(${USE_MY})
    message(我是图图小淘气 ${USE_MY})
    target_compile_definitions(MathFunctions
        PRIVATE USE_MY
    )
endif()