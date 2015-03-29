#include "VehicleFunctions.hpp"
#include "MemoryFunctions.hpp"
#include "PlayerFunctions.hpp"
#include <Shared/PipeMessages.hpp>

EXPORT unsigned int Client::VehicleFunctions::GetVehiclePointer()
{
	unsigned int ptr = 0;
	if (MemoryFunctions::ReadMemory(0xBA18FC, 4, &ptr) != 4)
		return 0;

	return ptr;
}

EXPORT int Client::VehicleFunctions::GetVehicleSpeed(float factor)
{
	DWORD ptr = GetVehiclePointer();
	if (ptr == NULL)
		return -1;

	float x = 0.0, y = 0.0, z = 0.0;
	if (MemoryFunctions::ReadMemory(ptr + 0x44, 4, &x) != 4)
		return -1;

	if (MemoryFunctions::ReadMemory(ptr + 0x48, 4, &y) != 4)
		return -1;

	if (MemoryFunctions::ReadMemory(ptr + 0x4C, 4, &z) != 4)
		return -1;

	float speed = sqrt((x*x) + (y*y) + (z*z)) * (float)100.0 * factor;
	return (int)speed;
}


