include("core/input")
include("core/entity")
include("safecall")
include("player")
local e = Entity("black.png", "obstacle")
e.set_mass(1)

local player = Player()
player.set_mass(2)

player.set_pos(1,1,0)
e.set_pos(5,5,0)
-- e.set_scale(0.5,0.5,0)
-- e.set_scale(2,2,0)
e.set_scale(1,1,0)
-- e.set_trigger(true)

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end
