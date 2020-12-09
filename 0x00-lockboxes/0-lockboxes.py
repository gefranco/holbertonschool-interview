#!/usr/bin/python3
def canUnlockAll(boxes):
    state_boxes = [0]*len(boxes)
    state_boxes[0] = 1
    i = 0
    j = 0
    while i < len(boxes):
        if state_boxes[i] == 1:
            while j < len(boxes[i]):
                key = boxes[i][j]
                if key >= len(boxes):
                    j += 1
                    continue
                if state_boxes[key] == 0 and key < i:
                    state_boxes[key] = 1
                    i = key - 1
                    j = len(boxes[i])
                else:
                    state_boxes[key] = 1
                    j += 1

        else:
            pass
            # if opened_boxes_search(boxes, i, state_boxes):
            #     state_boxes[i] = 1
            #     i -= 1
            # else:
            #     print(state_boxes)
            #     return False
        j = 0
        i += 1
        # print(boxes)
        # print(state_boxes)
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
