Primero se debe compilar PAQ con el siguiente comando:
g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o paq8n -LBLCR_LIBDIR -lcr_run -u cr_run_link_me

Luego, PAQ debe correrse con el siguiente comando:
cr_run ./paq8n [argumentos]

Para hacer un checkpoint se ejecuta desde otra terminal (en modo root):
cr_checkpoint --file nombre-checkpoint --term PID

Para restaurar el proceso:

cr_restart nombre-checkpoint
