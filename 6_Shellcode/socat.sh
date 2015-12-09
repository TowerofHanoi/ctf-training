socat tcp-l:4000,reuseaddr,fork exec:"strace ./redirectme"
#socat tcp-l:4000,reuseaddr,fork exec:"./redirectme"
