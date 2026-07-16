local project_name = "rtsyn-port"

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")

set_languages("c23")

add_requires("gtest")

target(project_name)
set_kind("static")
add_files("src/*.c")
add_files("src/**/*.c")
add_includedirs("include", { public = true })
add_includedirs("src")
add_headerfiles("include/(rtsyn/**.h)")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
