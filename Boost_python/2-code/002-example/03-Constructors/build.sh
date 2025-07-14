g++ -shared -o ctor.so -fPIC ctor.cpp \
    -I /usr/include/python3.8 \
    -lboost_python38