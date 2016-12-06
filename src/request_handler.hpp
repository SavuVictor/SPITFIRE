

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>
#include <boost/noncopyable.hpp>
#include "amf3.h"

namespace spitfire {
namespace server {

struct reply;
struct request;

/// The common handler for all incoming requests.
class request_handler
  : private boost::noncopyable
{
public:
  /// Construct with a directory containing files to be served.
  explicit request_handler();

  /// Handle a request and produce a reply.
  void handle_request(const request& req, reply& rep);

private:
  /// The directory containing the files to be served.
  std::string doc_root_;

};

} // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP
