workspace "Expense-Tracker"
    architecture "x64"
    configurations { "Debug", "Release" }
    
project "Expense-Tracker"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    systemversion "latest"

    targetdir "temp/bin/%{cfg.buildcfg}"
    objdir "temp/obj/%{cfg.buildcfg}"
    
    files
    {
        "src/Private/**.cpp",
        "src/Public/**.h",
        "src/**.cpp"
    }
