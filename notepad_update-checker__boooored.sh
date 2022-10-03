
function testi(){
  mangoUp="--update"
  dangoChecker="--checker"
  parametros=$#    #cantidad de parametros ingresados
  if [ $parametros -ne 1 ]; then
    echo -e "\n [*] Options:\t --update  --checker"
  else
    if [[ $1 == $mangoUp ]]; then
      mango=$(pwd)
      echo -e "\n\n\t\tUP\n" && cd $up && git pull origin master && echo -e "\n\n\t\tBLACKBOX\n" && cd $box && git pull origin master && echo -e "\n\n\t\tBRAIN\n" && cd $brain && git pull origin master && echo -e "\n\n\t\tBORED\n" && cd $bored && git pull origin master && cd ${mango} &&  echo -e "\n\n\t\tOK Ok ok...\n"

    elif [[ $1 == $dangoChecker ]]; then
      mango=$(pwd)
      echo -e "\n\n\t\tUP\n" && cd $up && git status && echo -e "\n\n\t\tBLACKBOX\n" && cd $box && git status && echo -e "\n\n\t\tBRAIN\n" && cd $brain && git status && echo -e "\n\n\t\tBORED\n" && cd $bored && git status && cd ${mango} &&  echo -e "\n\n\t\t checker...  OK Ok ok...\n"
    else
      echo -e "\n [*] Options:\t --update  --checker"
    fi
  fi
}
