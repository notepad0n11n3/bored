#!/bin/bash

tiempo=0.5
        # -d ejecuta en segundo plano
tmux new-session -d -t "helloAgain" && sleep $tiempo
        # -h horizontal   -v vertical
tmux rename-window "flush" && tmux split-window -h && tmux select-pane -t 1
                                                # tmux select-pane -t   cambiaFocusPanel
tmux send-keys "iptables --flush" C-m && sleep $tiempo
#tmux send-keys "comandHere/Text"    
  #  C-m  like a <CR> .vimrc
tmux send-keys "iptables --table nat --flush" C-m && sleep $tiempo
tmux send-keys "iptables --delete-chain" C-m && sleep $tiempo
tmux send-keys "iptables --table nat --delete-chain" C-m && sleep $tiempo
#---------------------------------
tmux select-pane -t 2 && tmux send-keys "iptables -L" C-m
# select-pane PASAMOD ALpanel2

#---------------------------------

tmux new-window -t helloAgain:3 -n "passwdAEO8" && sleep $tiempo &&  tmux send-keys "cat  /etc/passwd" C-m && sleep $tiempo 
#tmux new-windows -t sessionNameHere:numberVentanaAsignar

tmux select-window -t 1
#pasar a la ventana 1

