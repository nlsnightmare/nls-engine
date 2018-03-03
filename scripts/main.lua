include("core/input")
include("core/entity")
include("safecall")
include("player")
-- local e = Entity("box.png", "obstacle")
local player = Player()
player.set_mass(2)

local e1 = Entity("box.png", "obstacle")
e1.set_mass(1)
e1.set_pos(2,5,0)

local e2 = Entity("box.png", "obstacle")
e2.set_mass(3)
e2.set_pos(3,5,0)

e2.set_trigger(true)
-- e.set_pos(2,4,0)

local v = Vector2(1,1)
print(v)

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end


   print("FPS: "..1/dt)
end

