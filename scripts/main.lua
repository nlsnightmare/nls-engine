include("core/input")
include("core/entity")
include("player")
local player = Player()
local wall0 = Entity("box.png", "random")
local wall1 = Entity("box.png", "random")
local wall2 = Entity("box.png", "random")

player.set_pos(1,2,0)
player.set_scale(1,1,1)

wall0.set_pos(0,0,0)
wall1.set_pos(0,1,0)
wall2.set_pos(0,2,0)

local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end

   for i=1,#entities do
      for j = i+1,#entities do
	 if entities[i].intersects(entities[j]) then
	    entities[i].on_collision(entities[j])
	    entities[j].on_collision(entities[i])
	 end
      end
   end
end

