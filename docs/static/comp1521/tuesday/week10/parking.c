
ParksAvailableSem = 10
ParkingStation    = 1


Consumer // someone wants to park
{
   wait(ParksAvailableSem)
   park()
   if (ParkIsFull()) {
      wait(ParkingStation)
   }
   signal(ParksAvailableSem)
}


Producer
{
   if (ParkIsFull()) {
      sleep()
   }

   produce()
   signal(ParksAvailableSem)
}
