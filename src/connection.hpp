#ifndef HTTP_CONNECTION_HPP
#define HTTP_CONNECTION_HPP

#include <asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "reply.hpp"
#include "request.hpp"
#include "request_handler.hpp"

namespace spitfire {
namespace server {

class connection_manager;
class Client;

/// Represents a single connection from a client.
class connection: 
	public boost::enable_shared_from_this<connection>,
	private boost::noncopyable
{
public:
  /// Construct a connection with the given io_service.
  explicit connection(asio::io_service& io_service,connection_manager& manager, request_handler& handler);

  /// Get the socket associated with the connection.
  asio::ip::tcp::socket& socket();

  /// Start the first asynchronous operation for the connection.
  void start();

  /// Stop all asynchronous operations associated with the connection.
  void stop();

  void write(const char * data, const int32_t size);

private:
  /// Handle completion of a read operation.
  void handle_read_header(const asio::error_code& e,std::size_t bytes_transferred);
  void handle_read(const asio::error_code& e,std::size_t bytes_transferred);

  /// Handle completion of a write operation.
  void handle_write(const asio::error_code& e);

  /// Socket for the connection.
  asio::ip::tcp::socket socket_;

  /// The manager for this connection.
  connection_manager& connection_manager_;

  /// The handler used to process the incoming request.
  request_handler& request_handler_;

  /// Buffer for incoming data.
  boost::array<char, 8192*4> buffer_;

  /// The incoming request.
  request request_;

  /// The reply to be sent back to the client.
  reply reply_;

  int32_t size;

public:
  uint64_t uid;
  Client * client_;
};

typedef boost::shared_ptr<connection> connection_ptr;

} // namespace server
} // namespace http

#endif // HTTP_CONNECTION_HPP
