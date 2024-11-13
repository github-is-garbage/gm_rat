#include <GarrysMod/Lua/Interface.h>
#include <GarrysMod/Lua/LuaInterface.h>

#include <string>

char GetParameters(GarrysMod::Lua::ILuaBase* pLua, std::string& pStrHost, int& pPort)
{
	pLua->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	{
		// HOST
		pLua->PushString("_RT_HOST");
		pLua->RawGet(-2);

		if (!pLua->IsType(-1, GarrysMod::Lua::Type::String))
		{
			pLua->ThrowError("Invalid host!");

			pLua->Pop(2);
			return -1;
		}

		pStrHost = pLua->GetString(-1);
		pLua->Pop();

		// PORT
		pLua->PushString("_RT_PORT");
		pLua->RawGet(-2);

		if (!pLua->IsType(-1, GarrysMod::Lua::Type::Number))
		{
			pLua->ThrowError("Invalid port!");

			pLua->Pop(2);
			return -2;
		}

		pPort = pLua->GetNumber(-1);
		pLua->Pop();
	}
	pLua->Pop();

	return 0;
}

GMOD_MODULE_OPEN()
{
	std::string strHost;
	int iPort;

	int iResult = GetParameters(LUA, strHost, iPort);
	if (iResult) return 0; // Nice one retard

	GarrysMod::Lua::ILuaInterface* pLua = (GarrysMod::Lua::ILuaInterface*)LUA;
	
	pLua->Msg("%s:%d\n", strHost.c_str(), iPort);

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}