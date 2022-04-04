CPP_FLAGS = -std=c++0x
INC_FLAGS = -I../../meshtastic -I../../nanopb

all: open_port sendtext
	echo Building

open_port: serialib.o open_port.cpp admin.pb.o apponly.pb.o cannedmessages.pb.o channel.pb.o deviceonly.pb.o mesh.pb.o mqtt.pb.o portnums.pb.o radioconfig.pb.o remote_hardware.pb.o storeforward.pb.o telemetry.pb.o pb_encode.o  pb_decode.o pb_common.o
	g++ -o open_port $(CPP_FLAGS) $(INC_FLAGS) open_port.cpp admin.pb.o apponly.pb.o cannedmessages.pb.o channel.pb.o deviceonly.pb.o mesh.pb.o mqtt.pb.o portnums.pb.o radioconfig.pb.o remote_hardware.pb.o storeforward.pb.o telemetry.pb.o pb_encode.o pb_decode.o pb_common.o serialib.o `pkg-config --cflags --libs protobuf`

sendtext: serialib.o sendtext.cpp admin.pb.o apponly.pb.o cannedmessages.pb.o channel.pb.o deviceonly.pb.o mesh.pb.o mqtt.pb.o portnums.pb.o radioconfig.pb.o remote_hardware.pb.o storeforward.pb.o telemetry.pb.o pb_encode.o  pb_decode.o pb_common.o
	g++ -o sendtext $(CPP_FLAGS) $(INC_FLAGS) sendtext.cpp admin.pb.o apponly.pb.o cannedmessages.pb.o channel.pb.o deviceonly.pb.o mesh.pb.o mqtt.pb.o portnums.pb.o radioconfig.pb.o remote_hardware.pb.o storeforward.pb.o telemetry.pb.o pb_encode.o pb_decode.o pb_common.o serialib.o `pkg-config --cflags --libs protobuf`

serialib: serialib.cpp
	g++ -c serialib.cpp

pb_encode.o:
	gcc -c ../../nanopb/pb_encode.c

pb_decode.o:
	gcc -c ../../nanopb/pb_decode.c

pb_common.o:
	gcc -c ../../nanopb/pb_common.c

admin.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/admin.pb.cc

apponly.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/apponly.pb.cc

cannedmessages.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/cannedmessages.pb.cc

channel.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/channel.pb.cc

deviceonly.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/deviceonly.pb.cc

mesh.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/mesh.pb.cc

mqtt.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/mqtt.pb.cc

portnums.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/portnums.pb.cc

radioconfig.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/radioconfig.pb.cc

remote_hardware.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/remote_hardware.pb.cc

storeforward.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/storeforward.pb.cc

telemetry.pb.o:
	g++ -c $(CPP_FLAGS) ../../meshtastic/telemetry.pb.cc

clean:
	rm *.o open_port sendtext
