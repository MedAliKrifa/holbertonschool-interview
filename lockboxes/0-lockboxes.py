#!/usr/bin/python3
def canUnlockAll(boxes):
    # Initialize a set to keep track of the boxes we have access to
    # We start with the first box (index 0) already open
    open_boxes = {0}

    # Keep track of the keys we have but haven't tried to use yet
    unused_keys = []

    # Add all the keys in the first box to the unused_keys list
    unused_keys.extend(boxes[0])

    # Loop until we've tried all the unused keys and haven't opened any new boxes
    while unused_keys:
        # Take a key from the unused_keys list
        key = unused_keys.pop(0)

        # If the key opens a box we haven't already opened, add it to the open_boxes set
        if key < len(boxes) and key not in open_boxes:
            open_boxes.add(key)
            
            # Add all the keys in the newly opened box to the unused_keys list
            unused_keys.extend(boxes[key])

    # If we've opened all the boxes, return True, else return False
    return len(open_boxes) == len(boxes)
