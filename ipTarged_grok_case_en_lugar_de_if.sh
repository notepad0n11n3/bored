ipTarged() {
    # Obtiene el nombre de la sesión actual de tmux
    local session_name
    session_name=$(tmux display-message -p '#S')

    # Si no hay argumentos, muestra ayuda rápida
    if [ $# -eq 0 ]; then
        echo "Uso:"
        echo "  ipTarged --all        → pide tu IP y la IP objetivo (ventanas 0 y 1)"
        echo "  ipTarged <IP>         → cambia solo la IP objetivo en la ventana 1"
        echo "  ipTarged --here <IP>  → cambia solo la ventana ACTUAL con la IP objetivo"
        echo "  ipTarged --help       → muestra esta ayuda"
        return 1
    fi

    case "$1" in

        --help)
            echo "Comandos disponibles:"
            echo "  --all                Pide tu IP y la IP a atacar, actualiza ventanas 0 y 1"
            echo "  <IP>                 Cambia solo la ventana 1 (IP objetivo) con [IP]"
            echo "  --here <IP>          Cambia la ventana actual (donde estás) con [IP]"
            echo "  --help               Esta ayuda"
            ;;

        --all)
            # Ventana 0: tu IP → formato (mi_ip)
            echo -n "Mi IP: "
            read -r my_ip
            [[ -n "$my_ip" ]] && tmux rename-window -t "${session_name}:0" "(${my_ip})"

            # Ventana 1: IP objetivo → formato [ip_objetivo]
            echo -n "IP a morder: "
            read -r ip_target
            [[ -n "$ip_target" ]] && tmux rename-window -t "${session_name}:1" "[${ip_target}]"
            ;;

        --here)
            if [ -z "$2" ]; then
                echo "Error: --here requiere una IP"
                echo "Ejemplo: ipTarged --here 10.10.10.10"
                return 1
            fi

            local current_window
            current_window=$(tmux display-message -p '#I')  # número de ventana actual

            tmux rename-window -t "${session_name}:${current_window}" "[${2}]"
            echo "Ventana actual renombrada a: [${2}]"
            ;;

        *)
            # Uso normal: solo cambiar la ventana 1 con la IP que pases como argumento
            local ip_target="$1"
            tmux rename-window -t "${session_name}:1" "[${ip_target}]"
            echo "Ventana 1 renombrada a: [${ip_target}]"
            ;;
    esac
}
