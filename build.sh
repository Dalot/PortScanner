#/bin/bash
docker exec -it port_scanner bash -c "cd /opt/app && g++ -o Main Main.cpp && ./Main"