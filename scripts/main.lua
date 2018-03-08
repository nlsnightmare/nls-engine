include("core/input")
include("core/entity")
include("safecall")
include("player")
local e = Entity("box.png", "obstacle")
e.set_mass(5)
e.set_pos(5,2,0)

local player = Player()
player.set_mass(2)

-- e.set_scale(2,2,0)
-- e.set_trigger(true)

local v = Vector2(1,1)

local i = 0
function update(dt)

   for _,e in pairs(entities) do
      e.update(dt)
   end

   i = i + dt

end
