g++ -shared -o hello.so -fPIC hello.cpp \
    -I /usr/include/python3.8 \
    -lboost_python38