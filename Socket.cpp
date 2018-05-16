#include "Socket.h"

bool Socket::Create(const int type, const int protocol)
{
  _socket=WSASocket(AF_INET,
                    type,
                    protocol,
                    nullptr,
                    0,
                    WSA_FLAG_OVERLAPPED);
  return INVALID_SOCKET!=_socket;
}

void Socket::Close()
{
  if(INVALID_SOCKET!=_socket)
  {
    closesocket(_socket);
    _socket=INVALID_SOCKET;
  }
}

bool Socket::SetOptionInt(const int level, const int name, int val)
{
  return SOCKET_ERROR!=setsockopt(_socket,
                                  level,
                                  name,
                                  reinterpret_cast<char*>(&val),
                                  sizeof(val));
}