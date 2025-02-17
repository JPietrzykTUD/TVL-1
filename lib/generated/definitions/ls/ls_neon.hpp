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
 * @file /home/runner/work/TVLGen-1/TVLGen-1/lib/generated/definitions/ls/ls_neon.hpp
 * @date 23.03.2022
 * @brief Load/Store primitives. Implementation for neon
 */
#ifndef TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_DEFINITIONS_LS_LS_NEON_HPP
#define TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_DEFINITIONS_LS_LS_NEON_HPP

#include "../../declarations/ls.hpp"

namespace tvl {
   namespace details {
      template<  ImplementationDegreeOfFreedom Idof >
      struct load_impl< simd< int64_t, neon >, Idof > {
         using Vec = simd< int64_t, neon  >;
         static constexpr bool native_supported() {
            return true;
         }
   /*
    * @brief Loads data from aligned memory into a vector register.
    * @details todo.
    * @param memory Aligned memory which should be transferred into a vector register.
    * @return Vector containing the loaded data.
    */
         [[nodiscard]] 
         TVL_FORCE_INLINE static typename Vec::register_type apply(
            typename Vec::base_type const *  memory
         ) {
            return vld1q_s64( memory );
         }
      };
   } // end of namespace details for template specialization of load_impl for neon using int64_t.
   
   namespace details {
      template<  ImplementationDegreeOfFreedom Idof >
      struct loadu_impl< simd< int64_t, neon >, Idof > {
         using Vec = simd< int64_t, neon  >;
         static constexpr bool native_supported() {
            return true;
         }
   /*
    * @brief Loads data from (un)aligned memory into a vector register.
    * @details todo.
    * @param memory (Un)aligned memory which should be transferred into a vector register.
    * @return Vector containing the loaded data.
    */
         [[nodiscard]] 
         TVL_FORCE_INLINE static typename Vec::register_type apply(
            typename Vec::base_type const *  memory
         ) {
            return vld1q_s64( memory );
         }
      };
   } // end of namespace details for template specialization of loadu_impl for neon using int64_t.
   
   namespace details {
      template<  ImplementationDegreeOfFreedom Idof >
      struct set1_impl< simd< int64_t, neon >, Idof > {
         using Vec = simd< int64_t, neon  >;
         static constexpr bool native_supported() {
            return true;
         }
   /*
    * @brief Broadcasts a single value into all lanes of a vector register.
    * @details todo.
    * @param value Value which should be broadcasted.
    * @return Vector containing the same value in all lanes.
    */
         [[nodiscard]] 
         TVL_FORCE_INLINE static typename Vec::register_type apply(
            typename Vec::base_type  value
         ) {
            return vdupq_n_s64( value );
         }
      };
   } // end of namespace details for template specialization of set1_impl for neon using int64_t.
   
   namespace details {
      template<  ImplementationDegreeOfFreedom Idof >
      struct gather_impl< simd< int64_t, neon >, Idof > {
         using Vec = simd< int64_t, neon  >;
         static constexpr bool native_supported() {
            return false;
         }
   /*
    * @brief Transfers data from arbitrary locations into a vector register.
    * @details todo.
    * @param source Vector register containing values which should be preserved depending on the mask (if mask[i] == 0).
    * @param memory (Start)pointer of the memory (which is used as base for address calculation).
    * @param index Offsets (in base_type granularity) relative to the start pointer.
    * @param mask Mask indicating which lanes should be gathered.
    * @return Vector containing gathered data.
    */
         [[nodiscard]] TVL_NO_NATIVE_SUPPORT_WARNING
         TVL_FORCE_INLINE static typename Vec::register_type apply(
            typename Vec::register_type  source, 
            typename Vec::base_type const *  memory, 
            typename Vec::register_type  index, 
            typename Vec::mask_type  mask
         ) {
            static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );
            
            auto tmp = vdupq_n_s64( ( mask[ 0 ] == 0 ) ? source[ 0 ] : memory[ index[ 0 ] ] );
            return vsetq_lane_s64( ( ( mask[ 1 ] == 0 ) ? source[ 1 ] : memory[ index[ 1 ] ] ), tmp, 1 );

         }
      };
   } // end of namespace details for template specialization of gather_impl for neon using int64_t.
   
} // end of namespace tvl

#endif //TUD_D2RG_TVL__HOME_RUNNER_WORK_TVLGEN-1_TVLGEN-1_LIB_GENERATED_DEFINITIONS_LS_LS_NEON_HPP