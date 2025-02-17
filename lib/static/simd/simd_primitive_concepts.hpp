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
 * @file /home/runner/work/TVLGen-1/TVLGen-1/lib/static/simd/simd_primitive_concepts.hpp
 * @date 23.03.2022
 * @brief TODO.
 */
#ifndef TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_PRIMITIVE_CONCEPTS_HPP
#define TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_PRIMITIVE_CONCEPTS_HPP

#include "../utils/type_concepts.hpp"

namespace tvl {
   template< typename T >
   concept SimdPrimitiveImpl = requires {
      { T::native_supported() } -> std::same_as< bool >;
   } &&
      ( T::native_supported() || (! T::native_supported() ) );

   
} // end of namespace tvl

#endif //TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_PRIMITIVE_CONCEPTS_HPP