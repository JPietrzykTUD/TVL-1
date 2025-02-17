/*==========================================================================*
 * This file is part of the TVL - a template SIMD library.                  *
 *                                                                          *
 * Copyright 2022 TVL-Team, Database Research Group TU Dresden              *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *     http://www.apache.org/licenses/LICENSE-2.0                           *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 *==========================================================================*/
/*
 * @file /home/runner/work/TVLGen-1/TVLGen-1/lib/generated/extensions/simd/intel/avx512.hpp
 * @date 23.03.2022
 * @brief 
 */
#ifndef TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_EXTENSIONS_SIMD_INTEL_AVX512_HPP
#define TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_EXTENSIONS_SIMD_INTEL_AVX512_HPP

#include "immintrin.h"

namespace tvl {
   struct avx512 {
      using default_size_in_bits = std::integral_constant< std::size_t, 512 >;
      template< Arithmetic BaseType, std::size_t VectorSizeInBits = default_size_in_bits::value >
      struct types {
         using register_t __attribute__ ((
            __vector_size__ (
               VectorSizeInBits/sizeof(
                  TVL_DEP_TYPE(
                     (std::is_integral_v< BaseType >),
                     long long,
                     TVL_DEP_TYPE(
                        (sizeof( BaseType ) == 4),
                        float,
                        double
                     )
                  )
               )
            ), 
            __may_alias__, 
            __aligned__(VectorSizeInBits/sizeof(char))
            )) =
            TVL_DEP_TYPE(
               (std::is_integral_v< BaseType >),
               long long,
               TVL_DEP_TYPE(
                  (sizeof( BaseType ) == 4),
                  float,
                  double
               )
            );
         using mask_t =
            TVL_DEP_TYPE(
            ( VectorSizeInBits == 512 ),
            TVL_DEP_TYPE(
               ( sizeof( register_t ) / sizeof( BaseType ) ) == 64,
               __mmask64,
               TVL_DEP_TYPE(
                  ( sizeof( register_t ) / sizeof( BaseType ) ) == 32,
                  __mmask32,
                  TVL_DEP_TYPE(
                     ( sizeof( register_t ) / sizeof( BaseType ) ) == 16,
                     __mmask16,
                     __mmask8
                  )
               )
            ),
            TVL_DEP_TYPE(
               ( VectorSizeInBits == 256 ),
               TVL_DEP_TYPE(
                  ( sizeof( register_t ) / sizeof( BaseType ) ) == 32,
                  __mmask32,
                  TVL_DEP_TYPE(
                     ( sizeof( register_t ) / sizeof( BaseType ) ) == 16,
                     __mmask16,
                     __mmask8
                  )
               ),
               TVL_DEP_TYPE(
                  ( sizeof( register_t ) / sizeof( BaseType ) ) == 16,
                  __mmask16,
                  __mmask8
               )
            )
         );
      };
   };
   
} // end of namespace tvl

#endif //TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_EXTENSIONS_SIMD_INTEL_AVX512_HPP