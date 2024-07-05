mkdir -p firmware/included

cp lib/voxel/dist/libvoxel.h firmware/included/libvoxel.h

if [ "$1" == "--upload" ]; then
    pio run -t upload -e ${2:-um_feathers3}
else
    pio run
fi