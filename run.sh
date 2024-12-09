# if not exists comile file
if [ ! -f "tree" ]; then
    echo "compiling..."
    # compile the code
    g++ *.cpp -o tree -std=c++17
fi
# run the code
echo "running..."
./tree