#!/bin/bash

clear
P89X="OwO"  # <<== password Here  ++<<

echo "$P89X" | sudo -S apt update -y && echo "${P89X}" | sudo -S apt-get full-upgrade -y
echo "$P89X" | sudo -S service bluetooth restart

