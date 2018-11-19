#!/usr/bin/env python3

# Import the Halite SDK, which will let you interact with the game.
import hlt
from hlt import constants
from hlt.positionals import *

import random
import logging
import operator


# This game object contains the initial game state.
game = hlt.Game()
# Respond with your name.
game.ready("Unforettable")
ship_status = {}
turn = 0
def minind(arr):
    min = arr[0]
    minind = -1
    for i in range(len(arr)):
        if i < min:
              min = arr[i]
              minind = i
    return minind
    
    
def dropoff_benefit(val_ship, force):
    d_offs = me.get_dropoffs()
    dropoffs = []
    for i in d_offs:
        dropoffs.append(i.position)
    dropoffs.append(me.shipyard)
    lens = list(map(lambda x: game_map.calculate_distance(val_ship.position, x), dropoffs))
    if min(lens) > 14 and (force > 6):
        return True
    else:
        return False
        
        
def nearest_do(val_ship):
    d_offs = me.get_dropoffs()
    dropoffs = []
    for i in d_offs:
        dropoffs.append(i.position)
    dropoffs.append(me.shipyard.position)
    lens = list( map(lambda x: game_map.calculate_distance(val_ship.position, x), dropoffs))
    return dropoffs[minind(lens)]
    
    
def deposits(pos, eng):
    deposits = {}
    new_point = pos
    new_point = new_point.directional_offset((0,-1))
    if game_map[new_point].is_empty and new_point not in eng.values():
        deposits[game_map[new_point].halite_amount] = new_point
    new_point = new_point.directional_offset((-1,0))
    if game_map[new_point].is_empty and new_point not in eng.values():
        deposits[game_map[new_point].halite_amount] = new_point
    i = 3
    u = -1
    while i !=8:
        for j in range(i):
            new_point = new_point.directional_offset((0,-1*u))
            if game_map[new_point].is_empty and new_point not in eng.values():
                deposits[game_map[new_point].halite_amount] = new_point
        for k in range(i):
            new_point = new_point.directional_offset((-1*u,-0))
            if game_map[new_point].is_empty and new_point not in eng.values():
                deposits[game_map[new_point].halite_amount] = new_point
        i+=1
        u*=-1
    return deposits


def m_navigate(pos,dest):
    win_movs = []
    if dest.x > pos.x:
        win_movs.append((1,0))
    elif dest.x < pos.x:
        win_movs.append((-1,0))
    if dest.y > pos.y:
        win_movs.append((0,1))
    elif dest.y < pos.y:
        win_movs.append((0,-1))
    if pos == dest: win_movs.append((0,0))
    return win_movs


def avoid(ship, movs, ships, sol, av):
    can_avoid = False
    if ship.id in av:
        movs[ship.id] = [av[ship.id]]
    if movs[ship.id][0] == (0,0):
        return sol
    #logging.info('movs = {}'.format(list(movs.values())))
    for move in movs[ship.id]:
        for i in sol:
            if ship.position.directional_offset(move) == i[0].position.directional_offset(i[1]):
                if i[1] == (0,0) and (type(ship_status[i[0].id]) is int):
                    if ship_status[i[0].id] > 2:
                        can_avoid = True
                break
        else:
            logging.info(' move = {}'.format(move))
            sol.append((ship, move))
            return sol
    if len(movs[ship.id]) == 2 or (ship.id in av) or (not can_avoid):
        sol.append((ship, (0,0)))
        return sol
    else:
        av[ship.id] = movs[ship.id][0]
        move = av[ship.id]
        movs[ship.id] = [((move[0] + 1) % 2, (move[1] + 1) % 2), (-((move[0] - 1) % 2), -((move[1] - 1) % 2))]
        return avoid(ship, movs, ships, sol, av)
        
        
decrement = 3
engaged = {}
while True:
    # Get the latest game state.
    game.update_frame()
    moves = {}
    solid_moves = []
    avoiding = {}
    # You extract player metadata and the updated map metadata here for convenience.
    me = game.me
    game_map = game.game_map
    fleet_forces = len(me.get_ships())
    # A command queue holds all the commands you will run this turn.
    command_queue = []
    MAX_FLEET = game_map.width / 4
    for ship in me.get_ships():
    
        if ship.id not in ship_status:
            ship_status[ship.id] = "stady"
        
        logging.info("ship {} is status {}".format(ship.id, ship_status[ship.id]))
        
        if (ship.halite_amount < game_map[ship.position].halite_amount / 10) and ship.position != me.shipyard.position:
            ship_status[ship.id] = 2
            moves[ship.id] = [(0,0)]
        if type(ship_status[ship.id]) is int:
            if ship_status[ship.id] == 0:
                if ship.id in engaged:
                    ship_status[ship.id] = "stady"
                    if ship.position == engaged[ship.id]:
                        del engaged[ship.id]
                else:
                    ship_status[ship.id] = "stady"
                
            else:
                ship_status[ship.id] -= 1
                moves[ship.id] = [(0,0)]
                continue
            
        if game_map[ship.position].halite_amount < constants.MAX_HALITE/10 and (not ship_status[ship.id] == "moving"):
                ship_status[ship.id] = "stady"
                
        if ship.halite_amount >= constants.MAX_HALITE/2 or ship.is_full:
                ship_status[ship.id] = "returning"
                logging.info("ship {} returning".format(ship.id))
                if ship.id in engaged:
                    del engaged[ship.id]
                
        if (game_map[ship.position].halite_amount > constants.MAX_HALITE/8 and (not ship.is_full)):
            moves[ship.id] = [(0,0)]
            ship_status[ship.id] = 5
            continue
            
        '''    
        if dropoff_benefit == True and ship.halite_amount >= 4000:
            #logging.info("ship {} has {} halite. Establishing dropoff".format(ship.id, ship.halite_amount))
            command_queue.append(ship.make_dropoff())
            continue
        '''
        
        if ship_status[ship.id] == "returning":
            if ship.position == me.shipyard.position:
                ship_status[ship.id] = "stady"
                logging.info("ship {} redy for more".format(ship.id))
            else:
                move = m_navigate(ship.position, nearest_do(ship))
                moves[ship.id] = move
                #logging.info("ship {} returning to {}".format(ship.id, move))
                continue
        
        if ship_status[ship.id] == "moving":
            move = m_navigate(ship.position, engaged[ship.id])
            if ship.position == engaged[ship.id]:
                moves[ship.id] = [(0,0)]
                ship_status[ship.id] = 5
                continue
                
        if ship_status[ship.id]  == "stady":
            deps = deposits(ship.position, engaged)
            target = deps[max(deps)]
            move = m_navigate(ship.position, target)
            ship_status[ship.id] = "moving"
            engaged[ship.id] = target
        
        ##logging.info("ship position {}".format(ship.position))
        ##logging.info("ship cource {}, obstacles {}".format(ship.position.directional_offset(move), game_map[ship.position.directional_offset(move)].is_occupied))
        

        if ship_status[ship.id] == "moving":
            moves[ship.id] = move
            logging.info("ship will move: {}".format(move))
        
        logging.info("ship {} is status {}".format(ship.id, ship_status[ship.id]))

    for ship in me.get_ships():
        if moves[ship.id][0] == (0,0):
            solid_moves.append((ship, (0,0)))        
    for ship in me.get_ships():
        if not (ship in dict(solid_moves)):
            solid_moves = avoid(ship,moves, me.get_ships(), solid_moves, avoiding)
    
    for s in solid_moves:
        #logging.info("solid: {}".format(solid_moves))
        #logging.info("moves[ship.id][0] =".format(moves[ship.id][0]))
        command_queue.append(s[0].move(s[1]))    
    if turn >= 420:
        MAX_FLEET *= 0.5
    for ship in me.get_ships():
        if ship.position == me.shipyard.position:
            break
    else:
        if fleet_forces < MAX_FLEET and me.halite_amount >= constants.SHIP_COST:
            command_queue.append(game.me.shipyard.spawn())
    turn+=1
    # Send your moves back to the game environment, ending this turn.
    game.end_turn(command_queue)
            ##logging.info("ship {} about moving to {}".format(ship.id, i))
            ##logging.info("options {}".format(moves[ship.id]))