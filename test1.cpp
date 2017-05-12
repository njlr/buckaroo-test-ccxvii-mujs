#include <gtest/gtest.h>
#include <iostream>

extern "C" {
  #include <mujs.h>
}

TEST(mujs, basics) {

  auto const hello = [](js_State *J) {
  	const char *name = js_tostring(J, 1);
  	std::cout << "Hello, " << name << std::endl;
  	js_pushundefined(J);
  };

  js_State *J = js_newstate(NULL, NULL, JS_STRICT);

  js_newcfunction(J, hello, "hello", 1);
  js_setglobal(J, "hello");

  js_dostring(J, "hello('world');");

  js_freestate(J);
}
