Sample C++ client to show how to interact with Meshtastic devices.

To get started, install nanopb (see https://github.com/nanopb/nanopb). There are several ways to do this. See: https://jpa.kapsi.fi/nanopb/download/ has pre-built binaries. For this example, we will clone the repo and build it. We are assuming `bazel` is installed.


Clone, build, then return to the main directory:
```
git clone https://github.com/nanopb/nanopb
cd nanopb
bazel build
cd ..
```

Make sure it runs:
```
./nanopb/generator/protoc --version
libprotoc 3.19.4
```

Clone protobufs into a directory called "proto":
```
git clone git@github.com:meshtastic/Meshtastic-protobufs.git proto
```

Create meshtastic directory for generated code: (it could be called whatever you want)
```
mkdir meshtastic
./nanopb/generator/protoc -I=proto --cpp_out meshtastic `ls proto/*.proto`
```

Now you just need some simple cpp code to use it.

First example is using serialib - see https://github.com/imabot2/serialib
```
cd examples/using_serialib
make
```
