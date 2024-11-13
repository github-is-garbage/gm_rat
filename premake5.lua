PROJECT_GENERATOR_VERSION = 3

include("./garrysmod_common")

CreateWorkspace({name = "rat", abi_compatible = false, path = "./project/"})
	CreateProject({serverside = false, source_path = "./src", manual_files = false})
		cppdialect("c++20")

		-- IncludeHelpersExtended()
		-- IncludeLuaShared()
		-- IncludeDetouring()
		-- IncludeScanning()
		-- IncludeSDKCommon()
		-- IncludeSDKTier0()
		-- IncludeSDKTier1()
		-- IncludeSDKTier2()
		-- IncludeSDKTier3()
		-- IncludeSDKMathlib()
		-- IncludeSDKRaytrace()
		-- IncludeSteamAPI()

		files({
			"./src/**.*"
		})
