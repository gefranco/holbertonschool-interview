#!/usr/bin/python3
def canUnlockAll(boxes):
    state_boxes = [0]*len(boxes)
    state_boxes[0] = 1
    i = 0

    while i < len(boxes):
        if state_boxes[i] == 1:
            for j in range(len(boxes[i])):
                key = boxes[i][j]
                state_boxes[key] = 1

        else:
            if opened_boxes_search(boxes, i, state_boxes):
                state_boxes[i] = 1
                i -= 1
            else:
                return False
        i += 1

    if state_boxes.count(0) > 0:
        return False

    return True


def opened_boxes_search(opened, key, state_boxes):
    for ii in range(key, len(opened)):
        if state_boxes[ii] == 1:
            if opened[ii].count(key) > 0:
                return True

    return False

# search in opened boxes
# for ii in range (i + 1 , len(boxes)):
#       if state_boxes[ii] == 1:
#               if len(boxes[ii]) > 0:
#                       if boxes[ii].count(i) > 0:
#                               state_boxes[i] = 1
#                               i = i - 1
#                               break
