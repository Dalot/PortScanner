#/bin/bash
docker exec -it port_scanner bash -c "cd /opt/app && g++ Main.cpp -o Main -lsfml-system -lsfml-network && ./Main"