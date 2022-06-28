#!/usr/bin/bash

echo 'passwordhere' | sudo -S apt update && sudo apt-get full-upgrade -y && sudo updatedb
