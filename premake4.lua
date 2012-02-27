solution "pipeskel"
    configurations { "debug", "release" }

project "pipeskel-example"
    kind "ConsoleApp"
    language "C++"
    -- Includes
    includedirs { "include" }
    -- Sources
    files { "src/**.cpp" }
    -- Libraries
    libdirs { "lib", os.findlib("ticpp") }
    links { "ticpp" }

    configuration "debug"
        defines { "DEBUG" }
        flags { "Symbols" }
        targetdir "bin/debug"

    configuration "release"
        defines { "NDEBUG" }
        flags { "Optimize" }
        targetdir "bin/release"

