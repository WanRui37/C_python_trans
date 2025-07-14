g++ -shared -o classes.so -fPIC classes.cpp \
    -I /usr/include/python3.8 \
    -lboost_python38