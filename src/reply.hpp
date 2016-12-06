#ifndef HTTP_REPLY_HPP
#define HTTP_REPLY_HPP

#include <string>
#include <vector>
#include <asio.hpp>
#include "amf3.h"
#include "funcs.h"

namespace spitfire {
namespace server {

/// A reply to be sent to a client.
struct reply
{
  std::vector<amf3object> objects;

  /// Convert the reply into a vector of buffers. The buffers do not own the
  /// underlying memory blocks, therefore the reply object must remain valid and
  /// not be changed until the write operation has completed.
  std::vector<asio::const_buffer> to_buffers();
};

} // namespace server
} // namespace http

#endif // HTTP_REPLY_HPP
