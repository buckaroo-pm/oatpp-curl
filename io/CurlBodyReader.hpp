/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi, <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_curl_CurlBodyReader_hpp
#define oatpp_curl_CurlBodyReader_hpp

#include "./Curl.hpp"

#include "oatpp/core/data/stream/ChunkedBuffer.hpp"

namespace oatpp { namespace curl { namespace io {

/**
 * This class is wrapper over curl handles to provide input-stream like interface
 */
class CurlBodyReader {
private:
  std::shared_ptr<CurlHandles> m_handles;
  oatpp::data::stream::ChunkedBuffer m_buffer;
  os::io::Library::v_size m_position;
private:
  static size_t writeCallback(char *ptr, size_t size, size_t nmemb, void *userdata);
public:
  
  CurlBodyReader(const std::shared_ptr<CurlHandles>& curlHandles)
    : m_handles(curlHandles)
    , m_position(0)
  {
    curl_easy_setopt(m_handles->getEasyHandle(), CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(m_handles->getEasyHandle(), CURLOPT_WRITEDATA, this);
  }
  
  os::io::Library::v_size read(void *data, os::io::Library::v_size count);
  os::io::Library::v_size readNonBlocking(void *data, os::io::Library::v_size count);
  
  os::io::Library::v_size getAvailableBytesCount();
  
};
  
}}}

#endif /* oatpp_curl_CurlBodyReader_hpp */
