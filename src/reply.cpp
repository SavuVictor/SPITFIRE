#include "reply.hpp"
#include <string>
#include <boost/lexical_cast.hpp>

namespace spitfire {
namespace server {

std::vector<asio::const_buffer> reply::to_buffers()
{
  std::vector<asio::const_buffer> buffers;
  for (std::size_t i = 0; i < objects.size(); ++i)
  {
	  amf3writer * writer;

	  char tbuff[15000];
	  int length = 0;
	  writer = new amf3writer(tbuff+4);

	  writer->Write(objects[i]);

	  (*(int*)tbuff) = length = writer->position;
	  ByteSwap(*(int*)tbuff);

	  buffers.push_back(asio::buffer(tbuff, length+4));
	  delete writer;
  }
  return buffers;
}

} // namespace server
} // namespace http
