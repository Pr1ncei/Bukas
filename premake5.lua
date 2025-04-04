workspace "Bukas"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"

project "Bukas"
    location "Bukas"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Bukas/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "BK_PLATFORM_WINDOWS", 
            "BK_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/ArchiCode")
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        optimize "On"

    filter { "system:windows" }
        buildoptions "/utf-8"
    

project "ArchiCode"
    location "ArchiCode"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Bukas/vendor/spdlog/include",
        "Bukas/src"
    }

    links {
        "Bukas"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "BK_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "BK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BK_DIST"
        optimize "On"

    filter { "system:windows" }
        buildoptions "/utf-8"
    