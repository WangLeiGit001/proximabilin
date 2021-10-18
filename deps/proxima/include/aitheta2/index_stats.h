/**
 *   Copyright 2021 Alibaba, Inc. and its affiliates. All Rights Reserved.
 * 
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *   
 *       http://www.apache.org/licenses/LICENSE-2.0
 *   
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.

 *   \author   Hechong.xyf
 *   \date     Oct 2019
 *   \brief    Interface of AiTheta Index Stats
 */

#ifndef __AITHETA2_INDEX_STATS_H__
#define __AITHETA2_INDEX_STATS_H__

#include "index_params.h"

namespace aitheta2 {

/*! Index Stats
 */
class IndexStats {
 public:
  //! Test if the element is exist
  bool has_attribute(const std::string &key) const {
    return attributes_.has(key);
  }

  //! Set the value of key in T
  template <typename T>
  bool set_attribute(const std::string &key, T &&val) {
    return attributes_.set<T>(key, std::forward<T>(val));
  }

  //! Retrieve attribute with key
  template <typename T>
  bool get_attribute(const std::string &key, T *out) const {
    return attributes_.get<T>(key, out);
  }

  //! Erase the pair via a key
  bool erase_attribute(const std::string &key) {
    return attributes_.erase(key);
  }

  //! Clear the attributes
  void clear_attributes(void) {
    attributes_.clear();
  }

  //! Retrieve attributes
  const IndexParams &attributes(void) const {
    return attributes_;
  }

  //! Retrieve mutable attributes
  IndexParams *mutable_attributes(void) {
    return &attributes_;
  }

 private:
  //! Members
  IndexParams attributes_{};
};

}  // namespace aitheta2

#endif  // __AITHETA2_INDEX_STATS_H__
