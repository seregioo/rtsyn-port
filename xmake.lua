local project_name = "rtsyn-port"

set_license("GPL-3.0-or-later")

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

local rtsyn_modules = {
	{ path = "port", name = "port" },
	{ path = "port/value/str", name = "str" },
}

for _, rtsyn_module in ipairs(rtsyn_modules) do
	local tests_name = "tests/" .. rtsyn_module.path .. "-tests"
	target(tests_name)
	set_kind("binary")
	add_deps(project_name)
	add_packages("gtest")
	add_links("gtest_main")
	add_includedirs("src")
	add_files("tests/" .. rtsyn_module.path .. ".cpp")
	add_tests(rtsyn_module.name)
end
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
