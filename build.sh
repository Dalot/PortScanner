#/bin/bash
#docker exec -it port_scanner bash -c "cd /opt/app && g++ PortScanner.cpp -o PortScanner -lsfml-system -lsfml-network && ./PortScanner"
g++ Main.cpp -o Main -lsfml-system -lsfml-network && ./Main