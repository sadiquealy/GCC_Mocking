if you are writing unit test for a function which uses a third party library or system functions we need to mock functions to simulate failure cases.

In C language if you are using gcc compiler there is compiler flag to mock a function(-Wl,--wrap flag = Function_Name).
suppose i have to mock the function foo with syntax as shown below
unsigned int foo (char* input);
then while compiling pass the compiler flag as below

gcc file.c "-Wl,--wrap=foo" -o out

wrapped foo function will look as shown below

unsigned int __wrap_foo(char* input)
{
  printf("'wrapped funtion");
  return 1;
}

So if you are using the wrap flag for a function all call instances of function of foo will be redirected to  __wrap_foo() call.
Also if you want the real implementation you can call real function with __real_foo() with this flag on while compiling.


Recently I came across c language unit test library called cmocka where it uses this feature of gcc to mock.