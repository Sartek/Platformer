local libSFML = "../dependencies/SFML/build/lib"
local includeSFML = "../dependencies/SFML/include"

workspace "Platformer"
	configurations { "Debug", "Release" }
	location "build"
	
project "Platformer"
	location "build"
	kind "WindowedApp"
	language "C++"
	targetdir "bin"
	
	files { "src/*.h", "src/*.cpp", "src/*.hpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		optimize "On"
		links { "sfml-system-d", "sfml-window-d", "sfml-graphics-d" }
		libdirs { libSFML }
		includedirs { includeSFML }
		targetsuffix "-d"
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		flags {  }
		linktimeoptimization "On"
		optimize "Full"
		links { "sfml-system", "sfml-window", "sfml-graphics" }
		libdirs { libSFML }
		includedirs { includeSFML }