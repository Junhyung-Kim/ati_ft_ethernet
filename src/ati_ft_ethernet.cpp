#include "ati_ft_ethernet/ati_ft_ethernet.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "optoforce_node");

  Response r;
  SOCKET_HANDLE socketHandle;

  atiforceROS ft;

  int i;

  if (ft.Connect(&socketHandle, "192.168.1.1" , PORT) != 0)
  {
    fprintf(stderr, "Could not connect to device...");
    return -1;
  }
  else
  {
    fprintf(stderr, "connect device!!!");
  }
  
  while(1)
  {
    ft.SendCommand(&socketHandle);
    r = ft.Receive(&socketHandle);
    ft.ftPublish(r);
    ros::spinOnce();
  }

  ft.Close(&socketHandle);

  return 0;
}
