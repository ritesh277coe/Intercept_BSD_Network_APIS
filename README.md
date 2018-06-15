# Intercept_BSD_Network_APIS
A sample project to demonstrate how to intercept BSD network calls in C/Cpp program on Linux platform.

# Possible usecase:
Instead of scrutinizing all the functions present inside main application that make network connection, its preferrable to have one place for all network level checks.

# Project Requirements:
1) All the BSD network calls made through main application should be intercepted.
2) All the network calls inside the Dynamic Library SHOULD NOT be intercepted by the hook defined in main application.
3) For POC, Project is overriding connect api of BSD. <br>

# Things to watchout:
1) \_\_connect\_\_ is the glibc function that makes connect system call.
2) connect when called from main application will be intercepted by locally defined connect function. This interception can be used to add    ACL logic on IP:PORT
3) connect when called inside dynamic library SHOULD NOT be intercepted by main connect.
4) See how __function_in_so_which_calls_connect__ when called from main application does not call connect of main, instead calls wrapper __\_\_wrap_connect\_\___ function.
   
# How to compile code:
1) __For creating dynamic library__.<br>
  gcc -ggdb -O0 -shared -Wl,-wrap,connect -o libtest.so -fPIC connect.c
  
2) __For creating main executable__ (assuming libtest.so is at /home/user/work)<br>
  gcc -g -O0 main.c -L/home/user/work -ltest -o mainapp
