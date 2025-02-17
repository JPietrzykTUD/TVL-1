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
 * @file /home/runner/work/TVLGen-1/TVLGen-1/lib/static/simd/simd_type_concepts.hpp
 * @date 23.03.2022
 * @brief TODO.
 */
#ifndef TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_TYPE_CONCEPTS_HPP
#define TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_TYPE_CONCEPTS_HPP

#include <type_traits>
#include <concepts>
#include "../utils/type_concepts.hpp"

namespace tvl {
   template< typename T, typename U >
   concept TargetExtension = Arithmetic< U > && requires {
      typename T::default_size_in_bits;
      typename T:: template types< U >;
      typename T:: template types< U >::register_t;
      typename T:: template types< U >::mask_t;
   };
   template< typename T >
   concept VectorProcessingStyle = requires {
      typename T::base_type;
      typename T::target_extension;
      typename T::register_type;
      typename T::mask_type;
      { T::vector_size_b() } -> std::same_as< std::size_t >;
      { T::vector_size_B() } -> std::same_as< std::size_t >;
      { T::vector_element_count() } -> std::same_as< std::size_t >;
      { T::vector_alignment() } -> std::same_as< std::size_t >;
      { T::vector_mask_ratio() } -> std::same_as< std::size_t >;
      { T::mask_shift() } -> std::same_as< std::size_t >;
   } &&
      Arithmetic< typename T::base_type > &&
      TargetExtension< typename T::target_extension, typename T::base_type > &&
      ( T::vector_size_b() > 0 ) &&
      ( T::vector_size_B() > 0 ) &&
      ( T::vector_element_count() > 0 ) &&
      ( T::vector_alignment() > 0 ) &&
      ( T::vector_mask_ratio() > 0 ) &&
      ( T::mask_shift() > 0 );

   struct native{};
   struct workaround{};
   template< class T >
   concept ImplementationDegreeOfFreedom = std::is_same_v< T, native > || std::is_same_v< T, workaround >;

   
} // end of namespace tvl

#endif //TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_STATIC_SIMD_SIMD_TYPE_CONCEPTS_HPP