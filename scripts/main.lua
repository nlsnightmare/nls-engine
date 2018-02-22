include("core/input")
include("core/entity")
include("player")
local player = Player()

player.set_scale(2,2,1)


local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end

