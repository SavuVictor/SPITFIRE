#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <vector>
#include "amf3.h"

namespace spitfire {
namespace server {

class connection;

/// A request received from a client.
struct request
{
  int32_t size;
  std::string cmd;
  std::string uri;
  amf3object object;
  connection * connection;
};

} // namespace server
} // namespace http

#endif // HTTP_REQUEST_HPP
